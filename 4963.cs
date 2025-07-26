public class Example
{
    static int w;
    static int h;
    static int[][] map;
    static bool[][] visited;
    static int[] dx = { -1, 1, 0, 0, -1, 1, -1, 1};
    static int[] dy = { 0, 0, -1, 1, 1, -1, -1, 1};
    static int island = 0;
    public static void Main(string[] args)
    {
        var sr = new StreamReader(Console.OpenStandardInput());
        var sw = new StreamWriter(Console.OpenStandardOutput());

        while (true)
        {
            string str = sr.ReadLine();
            if (str == "0 0")
            {
                break;
            }
            string[] strArr = str.Split(" ");
            
            w = int.Parse(strArr[0]);
            h = int.Parse(strArr[1]);

            map = new int[h][];
            visited = new bool[h][];
            for (int i = 0; i < h; i++)
            {
                map[i] = new int[w];
                visited[i] = new bool[w];
            }

            for (int i = 0; i < h; i++)
            {
                string[] mapStr = sr.ReadLine().Split(" ");
                for (int j = 0; j < mapStr.Length; j++)
                {
                    map[i][j] = int.Parse(mapStr[j]);
                }
            }

            island = 0;
            for (int y = 0; y < h; y++)
            {
                for (int x = 0; x < w; x++)
                {
                    if (!visited[y][x] && map[y][x] == 1)
                    {
                        island ++;
                        DFS(x, y);//새섬 발견
                    }
                }
            }
            sw.WriteLine(island);            
        }
        
        sw.Flush();
    }

    public static void DFS(int startX, int startY)//더이상 근접한 1이 없으므로 빠져나옴
    {
        visited[startY][startX] = true;
        
        for (int i = 0; i < 8; i++)
        {
            int nx = startX + dx[i];
            int ny = startY + dy[i];

            if (nx >= 0 && ny >= 0 && nx < w && ny < h)//크기를 벗어나는지 확인
            {
                if (!visited[ny][nx] && map[ny][nx] == 1)
                {
                    DFS(nx, ny);
                }
            }
        }
    }
}