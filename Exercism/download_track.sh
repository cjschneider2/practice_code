curl -LS https://exercism.io/tracks/rust/exercises | grep "/tracks/rust/exercises/" | awk '{print $3}' | cut -d/ -f5 | cut -d\" -f1 > exercises.txt
while read in; do exercism download --exercise="$in" --track=rust; done < exercises.txt
