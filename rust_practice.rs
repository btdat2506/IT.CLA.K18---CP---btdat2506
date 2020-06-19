use std::io;

fn test()
{
    return;
}

fn main()
{
    let mut idx:i64;
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    idx = input.trim().parse().unwrap();
    println!("{}", idx);
}