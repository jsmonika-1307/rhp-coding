class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int z=0,o=0,l=0;
        for(int i=0;i<s.length();i++){
        if(s.charAt(i)=='0'){
            if(i>0&&s.charAt(i-1)=='1'){
                z=0;
                o=0;
            }
            z++;
        }else{
            o++;
            l=Math.max(l,2*Math.min(z,o));
        }
    }return l;
}}