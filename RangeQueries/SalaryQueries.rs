use std::io;
use std::io::{BufWriter, stdout, Stdout, Write};
// use std::mem::swap;
// use std::cmp::{max, min, Ordering};
// use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet, VecDeque, BinaryHeap};
use std::ops::{Add, AddAssign, Sub, SubAssign, Mul, MulAssign, Div, DivAssign, Neg};

// const MOD: i64 = 1_000_000_007;
// const MOD: i64 = 998_244_353;
// const BIG_INF: i64 = 1_000_000_000_000_000_000;
// const SMALL_INF: i32 = 1_000_000_000;
// const MAX_LIM: i32 = 1_000_000;

// const DIR4: [(i32, i32); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];
// const DIR8: [(i32, i32); 8] = [
//     (1, 0), (0, 1), (-1, 0), (0, -1),
//     (1, 1), (1, -1), (-1, 1), (-1, -1)
// ];

fn solve(reader: &mut Reader, writer: &mut BufWriter<Stdout>) {
    let (n, q): (i32, i32) = (reader.next(), reader.next());
    let mut p: Vec<i32> = (0..n).map(|_| reader.next()).collect();
    let query: Vec<(char, i32, i32)> = (0..q).map(|_| (reader.next(), reader.next(), reader.next())).collect();

    let mut all_num: Vec<i32> = p.clone();
    for i in 0..q as usize {
        if query[i].0 == '!' {
            all_num.push(query[i].2);
        } else {
            all_num.push(query[i].1);
            all_num.push(query[i].2);
        }
    }
    all_num.sort();

    let mut distinct_num: Vec<i32> = Vec::new();
    distinct_num.push(all_num[0]);
    for i in 1..all_num.len() {
        if all_num[i] != all_num[i - 1] {
            distinct_num.push(all_num[i]);
        }
    }

    let mut fen_tree: FenwickTree<i64> = FenwickTree::new(distinct_num.len());
    for &x in &p {
        let pos: i32 = distinct_num.binary_search_by_key(&x, |&x| x).unwrap() as i32;
        fen_tree.inc(pos, 1);
    }

    for &(t, t1, t2) in &query {
        if t == '!' {
            let (k, x): (i32, i32) = (t1 - 1, t2);
            let new_pos: i32 = distinct_num.binary_search_by_key(&x, |&x| x).unwrap() as i32;
            let old_pos: i32 = distinct_num.binary_search_by_key(&p[k as usize], |&x| x).unwrap() as i32;

            fen_tree.inc(old_pos, -1);
            fen_tree.inc(new_pos, 1);
            p[k as usize] = x;
        } else {
            let (mut l, mut r): (i32, i32) = (t1, t2);
            l = distinct_num.binary_search_by_key(&l, |&x| x).unwrap() as i32;
            r = distinct_num.binary_search_by_key(&r, |&x| x).unwrap() as i32;

            let freq: i64 = fen_tree.get_for(l, r);
            writeln!(writer, "{}", freq).ok();
        }
    }
}

#[derive(Debug, Clone, PartialEq)]
struct FenwickTree<T> where
    T: Default + Copy + PartialEq +
    Add + Sub + AddAssign + SubAssign {
    tree: Vec<T>
}

#[allow(dead_code)]
impl<T> FenwickTree<T> where
    T: Default + Copy + PartialEq +
    Add<Output = T> + Sub<Output = T> + AddAssign + SubAssign {
    fn new(max_size: usize) -> Self {
        Self { tree: vec![T::default(); max_size + 1] }
    }

    fn from(a: &Vec<T>) -> Self {
        let mut tree = Self { tree: vec![T::default(); a.len() + 1] };
        for (ind, &x) in a.iter().enumerate() {
            tree.inc(ind as i32, x);
        }
        tree
    }

    fn inc(&mut self, mut ind: i32, val: T) {
        ind += 1;
        while ind < self.tree.len() as i32 {
            self.tree[ind as usize] += val;
            ind += ind & (-ind);
        }
    }

    fn get_for(&mut self, l: i32, r: i32) -> T {
        if l > r {
            panic!("Invalid Range! (l <= r)");
        }
        self.get(r) - self.get(l - 1)
    }

    fn get(&mut self, mut ind: i32) -> T {
        ind += 1;
        let mut sum: T = T::default();
        while ind > 0 {
            sum += self.tree[ind as usize];
            ind -= ind & (-ind);
        }
        sum
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