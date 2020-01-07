class Solution {
    fun solution(n: Int): String {
        var answer = StringBuilder()
        for (i in 0 until n) {
            if (i and 1 > 0) {
                answer.append(second)
            } else answer.append(first)

        }
        return answer.toString()
    }

    companion object {
        const val first = "수"
        const val second = "박"
    }
}