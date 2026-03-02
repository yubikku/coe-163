use std::time::{Instant, Duration};

/// Core algorithm: O(N) complexity 
fn find_min_combi(n: usize, start: &str, end: &str) -> u32 {
    let s_bytes = start.as_bytes();
    let e_bytes = end.as_bytes();
    let mut total_turns = 0;

    for i in 0..n {
        // Convert ASCII to digit [cite: 11]
        let s = (s_bytes[i] - b'0') as i32;
        let e = (e_bytes[i] - b'0') as i32;
        
        // Governing formula: min(|s-e|, 10-|s-e|) [cite: 69]
        let diff = (s - e).abs();
        total_turns += diff.min(10 - diff) as u32;
    }
    total_turns
}

fn main() {
    // Profiling lengths: N = 10, 20, ..., 100 
    let n_values = (10..=100).step_by(10);
    let iterations = 1000;

    println!("{:>3} | {:>12} | {:>12} | {:>12}", "N", "Avg (ns)", "Min (ns)", "Max (ns)");
    println!("----------------------------------------------------------");

    for n in n_values {
        // Generate strings to avoid integer overflow for N=100 
        let start = "1".repeat(n); 
        let end = "9".repeat(n);

        let mut runtimes = Vec::with_capacity(iterations);

        for _ in 0..iterations {
            let now = Instant::now();
            let _ = find_min_combi(n, &start, &end);
            runtimes.push(now.elapsed());
        }

        let total: Duration = runtimes.iter().sum();
        let avg = total / iterations as u32;
        let min = runtimes.iter().min().unwrap();
        let max = runtimes.iter().max().unwrap();

        println!("{:>3} | {:>12?} | {:>12?} | {:>12?}", n, avg.as_nanos(), min.as_nanos(), max.as_nanos());
    }
}