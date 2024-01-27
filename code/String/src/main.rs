use std::*;

fn z(a:String,b:String){
    let z:Vec<u64>=Vec::new();
    let sa=a.chars();
    let sb=b.chars();
    let la=a.len();
    let lb=b.len();
    let mut i=0;
    while i<la && i<lb && a[i]==b[i]{
        i+=1;
    }
    for i in 0..la{
        
    }
}

fn main() -> io::Result<()>{
    let mut a=String::new();
    let mut b=String::new();
    io::stdin().read_line(&mut a)?;
    io::stdin().read_line(&mut b)?;
    println!("Hello, world!");
    Ok(())
}
