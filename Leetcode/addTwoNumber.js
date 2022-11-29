let array = [];
let count;
var addTwoNumbers = function (l1, l2) {
  if (l1.length !== l2.length) {
    if (l1.length > l2.length) {
      let zorvv = l1.length - l2.length;
      for (i = 0; i < zorvv; i++) {
        l2.push(0);
      }
    } else {
      let zorvv = l2.length - l1.length;
      for (i = 0; i < zorvv; i++) {
        l1.push(0);
      }
    }
  }
  let sum = l1[l1.length - 1] + l2[l2.length - 1];
  array.push(sum);
  for (i = 1; i < l1.length; i++) {
    if (count === 1) {
      sum = l1[l1.length - 1 - i] + l2[l1.length - 1 - i] + 1;
      console.log(l1.length - 1 - i);
    } else {
      sum = l1[l1.length - 1 - i] + l2[l1.length - 1 - i];
    }
    if (sum > 9) {
      sum -= 10;
      array.push(sum);
      count = 1;
    } else {
      array.push(sum);
      count = 0;
    }
  }
  console.log(array);
};

addTwoNumbers([0], [0]);
