def to_rna(dna_strand):
    map_dna_to_rna = {
        "G": "C",
        "C": "G",
        "T": "A",
        "A": "U",
    }
    rna = []
    for dna in dna_strand:
        rna.append(map_dna_to_rna.get(dna, ""))
    return "".join(rna)
