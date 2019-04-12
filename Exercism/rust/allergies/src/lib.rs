#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Allergen {
    Eggs = 1,
    Peanuts = 2,
    Shellfish = 4,
    Strawberries = 8,
    Tomatoes = 16,
    Chocolate = 32,
    Pollen = 64,
    Cats = 128
}

impl Allergen {
    fn value(&self) -> usize {
        *self as usize
    }

    fn list() -> [Allergen; 8] {
        [ Allergen::Eggs, Allergen::Peanuts,
          Allergen::Shellfish, Allergen::Strawberries,
          Allergen::Tomatoes, Allergen::Chocolate,
          Allergen::Pollen, Allergen::Cats ]
    }

}

pub struct Allergies {
    score: usize
}

impl Allergies {
    pub fn new(score: usize) -> Allergies {
        Allergies { score: score }
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        let mut ret = Vec::<Allergen>::new();
        for allergen in Allergen::list().iter() {
            if self.is_allergic_to(allergen) {
                ret.push(allergen.clone());
            }
        }
        ret
    }

    pub fn is_allergic_to(&self, test: &Allergen) -> bool {
        self.score & test.value() > 0
    }
}