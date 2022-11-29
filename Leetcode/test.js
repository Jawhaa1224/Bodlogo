/**
 * @param {number} x
 * @return {boolean}
 */
let x = 121;
var isPalindrome = () => {
  let carry;
  let plus = "";
  let y = x;
  // if (y < 0) {
  while (y != 0) {
    carry = y % 10;
    plus = plus * 10 + carry;
    y = parseInt(y / 10);
  }
  if (plus === x) {
    return true;
  } else {
    return false;
  }
  // } else {
  //   return false;
  // }
};
// isPalindrome(121);
// console.log("Y:" + (-121 % 10));
