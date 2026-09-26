class Solution {
    public boolean canTransform(int[] source, int[] target) {
        long s1 = 0;
        long s2 = 0;
        for (int num : source) {
            s1 += num;
        }
        for (int num : target) {
            s2 += num;
        }
        return s1 == s2;
    }
} 