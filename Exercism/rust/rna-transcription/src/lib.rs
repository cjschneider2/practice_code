#[derive(PartialEq, Debug)]
pub struct RibonucleicAcid {
    source: String,
}

impl RibonucleicAcid {
    pub fn new(source: &str) -> RibonucleicAcid {
        RibonucleicAcid { source: source.to_string() }
    }
}

#[derive(PartialEq, Debug)]
pub struct DeoxyribonucleicAcid {
    source: String,
}

impl DeoxyribonucleicAcid {
    pub fn new(source: &str) -> DeoxyribonucleicAcid {
        DeoxyribonucleicAcid { source: source.to_string() }
    }

    pub fn to_rna(&self) -> RibonucleicAcid {
        let src: String = self.source
            .chars()
            .map(|c| match c {
                'G' => 'C',
                'C' => 'G',
                'T' => 'A',
                'A' => 'U',
                c => panic!("Unexpected input character: {}", c),
            })
            .collect();
        RibonucleicAcid::new(&src)
    }
}