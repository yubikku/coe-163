use std::time::Instant;

fn idx(i: usize, j: usize, n: usize) -> usize {
    i * n + j
}

// Fill with deterministic pseudo-random values (it'll do)
fn fill(v: &mut Vec<f64>) {
    for (i, x) in v.iter_mut().enumerate() {
        *x = (i as f64 % 100.0) / 100.0;
    }
}

fn mmm(a: &Vec<f64>, b: &Vec<f64>, c: &mut Vec<f64>, n: usize) {
    for i in 0..n {
        for j in 0..n {
            for k in 0..n {
                c[idx(i,j,n)] += a[idx(i,k,n)] * b[idx(k,j,n)];
            }
        }
    }
}

fn main() {
    let n = 800;
    let trials = 30;
    let mut time = 0.0;
    let mut duration;

    let mut a = vec![0.0f64; n*n];
    let mut b = vec![0.0f64; n*n];
    let mut c = vec![0.0f64; n*n];

    fill(&mut a);
    fill(&mut b);

    for _ in 0..trials {
        let start = Instant::now();
        mmm(&a, &b, &mut c, n);
        duration = start.elapsed();
        println!("{:?}", duration.as_secs_f64());
        time += duration.as_secs_f64();
    }

    println!("Average time: {:?}sec", time/(trials as f64));
}
