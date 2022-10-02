function balikanKata(kata) {
    var tes= " ";
   for (var i = kata.length-1; i >= 0; i--){
     tes = tes + kata[i];
   } 
  return tes;
}

// TEST CASES
console.log(balikanKata('Hello World and Coders')); // sredoC dna dlroW olleH
