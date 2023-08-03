use std::io;
use std::io::{BufWriter, stdout, Stdout, Write};
// use std::mem::swap;
// use std::cmp::{max, min, Ordering};
// use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet, VecDeque, BinaryHeap};
// use std::ops::{Add, AddAssign, Sub, SubAssign, Mul, MulAssign, Div, DivAssign, Neg};

// const MOD: i64 = 1_000_000_007;
// const MOD: i64 = 998_244_353;
const BIG_INF: i64 = 1_000_000_000_000_000_000;
// const SMALL_INF: i32 = 1_000_000_000;
// const MAX_LIM: i32 = 2_000_000;

// const DIR4: [(i32, i32); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];
// const DIR8: [(i32, i32); 8] = [
//     (1, 0), (0, 1), (-1, 0), (0, -1),
//     (1, 1), (1, -1), (-1, 1), (-1, -1)
// ];

fn bellman_ford(n: i32, edges: &Vec<(i32, i32, i64)>) -> Vec<i32> {
    let mut dist: Vec<i64> = vec![BIG_INF; n as usize];
    let mut par: Vec<i32> = vec![-1; n as usize];
    for _ in 0..n as usize - 1 {
        for &(u, v, w) in edges {
            if dist[u as usize] + w < dist[v as usize] {
                dist[v as usize] = dist[u as usize] + w;
                par[v as usize] = u;
            }
        }
    }

    let (mut bad, mut cycle): (bool, i32) = (false, -1);
    for &(u, v, w) in edges {
        if dist[u as usize] + w < dist[v as usize] {
            bad = true;
            cycle = v;
            break
        }
    }
    if !bad {
        return Vec::new();
    }

    let mut path: Vec<i32> = vec![cycle];
    while !path.contains(&par[cycle as usize]) && par[cycle as usize] != -1 {
        path.push(par[cycle as usize]);
        cycle = par[cycle as usize];
    }
    if par[cycle as usize] != -1 {
        path.push(par[cycle as usize]);
    }

    while path.first().unwrap() != path.last().unwrap() {
        path.remove(0);
    }

    path.reverse();
    path
}

fn solve(reader: &mut Reader, writer: &mut BufWriter<Stdout>) {
    let (n, m): (i32, i32) = (reader.next(), reader.next());
    let mut edges: Vec<(i32, i32, i64)> = (0..m)
        .map(|_| (reader.next(), reader.next(), reader.next())).collect();
    for (_, (u, v, _w)) in edges.iter_mut().enumerate() {
        *u -= 1;
        *v -= 1;
    }

    let neg_path: Vec<i32> = bellman_ford(n, &edges);
    if neg_path.is_empty() {
        writeln!(writer, "NO").ok();
    } else {
        writeln!(writer, "YES").ok();
        for &x in &neg_path {
            write!(writer, "{} ", x + 1).ok();
        }
    }
}

#[derive(Default)]
struct Reader {
    buffer: Vec<String>
}

#[allow(dead_code)]
impl Reader {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok()
                            .expect("Failed to parse!");
            }

            let mut input = String::new();
            io::stdin().read_line(&mut input)
                .expect("Failed to read!");

            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }

    fn next_chars(&mut self) -> Vec<char> {
        self.next::<String>().chars().collect()
    }
}

fn main() {
    let mut reader = Reader::default();
    let writer = &mut BufWriter::new(stdout());

    let is_multi_test: bool = false;
    let mut t: i32 = 1;

    if is_multi_test {
        t = reader.next();
    }

    for _i in 0..t {
        solve(&mut reader, writer);
    }
}