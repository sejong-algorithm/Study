import java.util.regex.Pattern

class Solution {
    fun solution(s: String): Boolean {
        return Pattern.matches("(^[0-9]{4}|[0-9]{6})", s)
    }
}