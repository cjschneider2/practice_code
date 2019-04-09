object Main extends App {
  val source = scala.io.Source.fromFile(args(0))
  val lines = source.getLines.filter(_.length > 0)
  for (l <- lines) {
    def age = l.toInt
    if ( age >= 0 && age <= 2) println("Still in Mama's arms")
    else if ( age >= 3 && age <= 4) println("Preschool Maniac")
    else if ( age >= 5 && age <= 11) println("Elementary school")
    else if ( age >= 12 && age <= 14) println("Middle school")
    else if ( age >= 15 && age <= 18) println("High school")
    else if ( age >= 19 && age <= 22) println("College");
    else if ( age >= 23 && age <= 65) println("Working for the man")
    else if ( age >= 66 && age <= 100) println("The Golden Years")
    else println("This program is for humans\n")
  }
}
