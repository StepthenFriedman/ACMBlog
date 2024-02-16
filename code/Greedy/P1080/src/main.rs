use std::*;
use std::io::BufRead;
//10^38

#[derive(Debug)]
struct ppl{
    left:u128,
    right:u128,
    plus:u128
}
fn main(){
    let cin = std::io::stdin();
    let mut s = String::new();
    cin.read_line(&mut s).unwrap();
    s.pop();
    let n:u128 = s.parse().unwrap();
    s.clear();
    cin.read_line(&mut s).unwrap();
    let mut v=vec![];
    let mut res=s.split_whitespace()
        .map(|x| x.parse::<u128>())
        .collect::<Result<Vec<u128>, _>>()
        .unwrap()[0];
    let mut overflow=0;
    for i in 0..n{
        s.clear();
        cin.read_line(&mut s).unwrap();
        let values = s
            .split_whitespace()
            .map(|x| x.parse::<u128>())
            .collect::<Result<Vec<u128>, _>>()
            .unwrap();
        assert!(values.len() == 2);
        res*=values[0];
        while res>=1000000000000000000 {
            res-=1000000000000000000;
            overflow+=1;
        }
        v.push(ppl{left:values[0],right:values[1],plus:values[0]*values[1]});
    }
    dbg!(&res);
    v.sort_by(|a,b| b.plus.cmp(&a.plus));
    let mut i=0;
    if overflow==0 {
        while res<v[i].plus && i<v.len() {
            res/=v[i].left;i+=1;
        }
        println!("{}",res/v[i].plus);
    }else{
        println!("{}",(overflow*1000000000000000000/v[i].plus)+res/v[i].plus);
    }
}
