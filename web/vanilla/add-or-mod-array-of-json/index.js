function movieChange(selectedMovie, selectedRating) {
  let i = 0;
  while (i <= array.length) {
    if (i < array.length) {
      if (array[i].movieName === selectedMovie) {
        array[i].movieRating = selectedRating;
        break;
      }
    } else {
      array.push({
        movieName: selectedMovie,
        movieRating: selectedRating,
      });
      break;
    }
    i++;
  }
}

let array = [
  { movieName: "300", movieRating: 3 },
  { movieName: "knight_and_day", movieRating: 2 },
];

console.log("original array\n", array, "\n=======");
movieChange("day_and_night", 7);
console.log("added day and night\n", array, "\n=======");
movieChange("knight_and_day", 5);
console.log("changed knight and day rating\n", array, "\n=======");
