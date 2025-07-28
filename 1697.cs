public class Example
{
    static int answer = 0;
    static bool[] visited;
    static int[] map;
    public static void Main(string[] args)
    {
        var sr = new StreamReader(Console.OpenStandardInput());
        var sw = new StreamWriter(Console.OpenStandardOutput());

        string[] pos = sr.ReadLine().Split(" ");

        int n = int.Parse(pos[0]);
        int k = int.Parse(pos[1]);

        visited = new bool[100001];
        map = new int[100001];
        for (int i = 0; i < 100001; i++)
        {
            map[i] = 0;
        }

        BFS(n, k);

        sw.WriteLine(answer);
        sw.Flush();
    }
    
    public static void BFS(int start, int k)
    {
        Queue<int> q = new Queue<int>();
        q.Enqueue(start);
        visited[start] = true;

        while (q.Count > 0)
        {
            int cur = q.Dequeue();
            for (int i = 0; i < 3; i++)
            {
                int move = 0;
                if (i == 0)
                {
                    move = cur + 1;
                }
                else if (i == 1)
                {
                    move = cur -1;
                }
                else if (i == 2)
                {
                    move = cur * 2;
                }

                if (move >= 0 && move < 100001 && !visited[move])
                {
                    map[move] = map[cur] + 1;   
                    q.Enqueue(move);
                    visited[move] = true;

                    if (move == k)
                    {
                        answer = map[move];
                        return;
                    }
                }
            }
        }
    }
}