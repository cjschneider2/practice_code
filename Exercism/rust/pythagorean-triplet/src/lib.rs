/// Find the product of the Pythagorean triplet which has a sum of 1000
/// Notes:
///     0) `x^2 + y^2 = z^2`
///     1) `x < y < z`
///     2) `z^2 < x^2 + y^2` can't be true (follows from (1))
///     3) upper bounds on `z === SUM`
///
pub fn find() -> Option<u32> {
    const SUM: u32 = 1000;

    for x in 1..SUM {

        // (1)
        let mut y = x + 1;
        let mut z = y + 1;

        // (3)
        while z <= SUM {

            // (2)
            while z*z < x*x + y*y { z += 1; }

            // End condition
            if x*x + y*y ==  z*z && z <= SUM && x + y + z == SUM {
                return Some(x*y*z);
            }

            y += 1;
        }
    }

    None
}
