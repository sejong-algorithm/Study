class Solution {
    fun solution(numbers: String): Int {
        var answer = 0

        //TODO 시작과 끝이 0인것은 계산하지 않는다.
        val list = numbers.map {
            it.toInt()
        }.forEachIndexed { index, s ->
            val front = s

        }





        return answer
    }
}

fun String.isPrime(): Boolean {
    with(toInt()) {
        if (this > 1) {
            for (j in 2 until this) {
                if (this % j == 0) {
                    return false
                }
            }
            return true
        } else {
            return false
        }
    }

}

fun main() {
    Solution().run {
        solution("4")
            .also { println(it) }
        solution("123456789")
            .also { println(it) }
    }
}