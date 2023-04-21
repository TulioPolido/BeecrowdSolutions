using System;
using System.Collections.Generic;

class teste {
    public static int[] visitados = new int[100];
    public static Dictionary<char, List<char>> dict = new Dictionary<char, List<char>>();
    public static List<char> resp = new List<char>();

    public static void dfs(char v) {
        visitados[Convert.ToInt32(v)-97] = 1;
        resp.Add(v);

        for(int i = 0; i < dict[v].Count; i++){
            if(visitados[Convert.ToInt32(dict[v][i])-97] == 0){
                dfs(dict[v][i]);
            }
        }
    }

    static void Main(string[] args) {

        int casos = int.Parse(Console.ReadLine());
        int caso = 1;

        while(casos-- > 0){
            dict.Clear();
            string linha = Console.ReadLine();
            string[] nums = linha.Split(' ');
            int vertices = int.Parse(nums[0]);
            int arestas = int.Parse(nums[1]);

            for(int i = 0; i < vertices; i++) {
                visitados[i] = 0;
                char j = Convert.ToChar(i+97);
                List<char> edges = new List<char>();
                dict.Add(j,edges);
            }

            while(arestas-- > 0){
                linha = Console.ReadLine();
                string[] v = linha.Split(' ');
                char char1 = char.Parse(v[0]);
                char char2 = char.Parse(v[1]);

                dict[char1].Add(char2);
                dict[char2].Add(char1);
            }

            int componentes = 0;
            Console.WriteLine("Case #{0}:",caso);

            for(int i = 0; i < vertices; i++){
                if(visitados[i] == 0){   
                    resp.Clear();
                    char v = Convert.ToChar(i+97);   
                    dfs(v);

                    resp.Sort();
                    for(int j = 0; j < resp.Count; j++){
                        Console.Write("{0},", resp[j]);
                    }
                    Console.WriteLine();
                    componentes++;
                }
            }

            Console.WriteLine("{0} connected components\n",componentes);
            caso++;
        }
    }
}