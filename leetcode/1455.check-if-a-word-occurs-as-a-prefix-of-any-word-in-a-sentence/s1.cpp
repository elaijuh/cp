// OJ:
// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// Author: github.com/elaijuh
// Time: O()
// Space: O()
/**
 * @param {string} sentence
 * @param {string} searchWord
 * @return {number}
 */
var isPrefixOfWord = function(sentence, searchWord) {
  const words = sentence.split(' ');
  let ans = -1;
  for (const[i, w] of words.entries()) {
    if (w.startsWith(searchWord)) {
      ans = i + 1;
      return ans;
    }
  }
  return ans;
};
