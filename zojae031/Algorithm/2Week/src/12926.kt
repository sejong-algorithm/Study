//class Solution {
//    fun solution(s: String, n: Int): String {
//        var answer = StringBuilder()
//        s.toCharArray().map { base ->
//            if (base != ' ')
//                (base + n).also { next ->
//                    if (next > 'z') return@map (next - 'z' + 'a'.toInt() - 1).toChar()
//                    else if (next > 'Z' && base < 'a') return@map (next - 'Z' + 'A'.toInt() - 1).toChar()
//                    else return@map next
//                }
//            else return@map ' '
//        }.forEach {
//            answer.append(it)
//        }
//        return answer.toString()
//    }
//}
