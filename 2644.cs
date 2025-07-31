public class Example
{
    static int answer = -1;
    public static void Main(string[] args)
    {
        var sr = new StreamReader(Console.OpenStandardInput());
        var sw = new StreamWriter(Console.OpenStandardOutput());
        
        int n = int.Parse(sr.ReadLine());
        string[] str = sr.ReadLine().Split(" ");

        int k = int.Parse(str[0]);
        int l = int.Parse(str[1]);
        
        List<int>[] relation = new List<int>[n+1];
        for (int i = 0; i < n + 1; i++)
        {
            relation[i] = new List<int>();
        }
        bool[] visited = new bool[n + 1];
        int[] visitNum = new int[n + 1];

        int m = int.Parse(sr.ReadLine());
        for (int i = 0; i < m; i++)
        {
            string[] strArr = sr.ReadLine().Split(" ");
            relation[int.Parse(strArr[0])].Add(int.Parse(strArr[1]));
            relation[int.Parse(strArr[1])].Add(int.Parse(strArr[0]));
        }

        BFS(k, l, relation, visited, visitNum);
        sw.WriteLine(answer);
        sw.Flush();
    }

    public static void BFS(int start, int target, List<int>[] relation, bool[] visited, int[] visitNum)
    {
        visited[start] = true;
        Queue<int> q = new Queue<int>();
        q.Enqueue(start);

        while (q.Count > 0)
        {
            int cur = q.Dequeue();
            foreach (int next in relation[cur])
            {
                if (!visited[next])
                {
                    visited[next] = true;
                    q.Enqueue(next);
                    visitNum[next] = visitNum[cur] + 1;
                    if (next == target)
                    {
                        answer = visitNum[next];
                        return;
                    }
                }
            }
        }
    }
}