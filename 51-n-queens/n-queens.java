class Solution {
    List<List<String>> ans=new ArrayList<>();

    public void solve(int n,int r,char[][]board,HashSet<Integer>cols,HashSet<Integer>diag,HashSet<Integer>antidiag){
        if(r==n){
            List<String>temp=new ArrayList<>();
            for(int i=0;i<n;i++)
            temp.add(new String(board[i]));
            ans.add(temp);
            return;
        }
        for(int c=0;c<n;c++){
            if(cols.contains(c)||diag.contains(r-c)||antidiag.contains(r+c)){
                continue;
            }
            board[r][c]='Q';
            cols.add(c);
            diag.add(r-c);
            antidiag.add(r+c);
            solve(n,r+1,board,cols,diag,antidiag);
            board[r][c]='.';
            cols.remove(c);
            diag.remove(r-c);
            antidiag.remove(r+c);
        }
    }

    public List<List<String>> solveNQueens(int n) {
   char[][] board=new char[n][n];
   for(int i=0;i<n;i++){
    Arrays.fill(board[i],'.');
   }

   solve(n,0,board,new HashSet<>(),new HashSet<>(),new HashSet<>());
   return ans;

    }
}