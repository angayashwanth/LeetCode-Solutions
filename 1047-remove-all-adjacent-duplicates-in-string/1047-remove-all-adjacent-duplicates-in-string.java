class Solution {
    public String removeDuplicates(String s) 
    {
        Stack<Character>st=new Stack<>();
        for(int i=0;i<s.length();i=i+1)
        {
            char ch = s.charAt(i);
            if(!st.isEmpty() && st.peek()== ch)
            st.pop();

            else
            st.push(ch);
        }
        StringBuilder sb = new StringBuilder();
        for(char ch:st)
        sb.append(ch);
        return sb.toString();
    }
}