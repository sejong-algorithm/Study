fun main() {
    Solution().solution(intArrayOf(3, 30, 34, 5, 9))
        .also { println(it) }
}

class Solution {
    fun solution(numbers: IntArray): String {
        var answer = ""
        //List<String> 으로 변환한다.
        numbers.sortedWith(Comparator { t1, t2 ->
            val front = t1.toString()
            val back = t2.toString()
            return@Comparator (back + front).compareTo(front + back)
        }).forEach {
            answer += it.toString()
        }

        return if (answer.startsWith('0')) "0" else answer
    }
}