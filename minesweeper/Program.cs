using System;

namespace MyApplication
{
    class Program
    {
        static Random rand = new Random();
        static void Mine_generate(int[,] matrix, int rowsize, int colsize, int minecount)
        {
            int i = 0;
            int minex, miney;
            while (i < minecount)
            {
                miney = rand.Next(0, rowsize);
                minex = rand.Next(0, colsize);
                if (matrix[miney, minex] == 0)
                {
                    matrix[miney, minex] = -1;
                    i++;
                }
            }
        }

        static int Check(int[,] matrix, int celly, int cellx, int rowsize, int colsize)
        {
            int[,] directions = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
            int i = 0, j, currenty, currentx, cellvalue = 0;
            for (i = 0; i < 8; i++)
            {
                currenty = celly + directions[i, 0];
                currentx = cellx + directions[i, 1];
                if (currenty < 0 || currenty > rowsize - 1 || currentx < 0 || currentx > colsize - 1)
                {
                    continue;
                }
                else
                {
                    if (matrix[currenty, currentx] == -1)
                    {
                        cellvalue++;
                    }
                }
            }
            return cellvalue;
        }

        static void Main(string[] args)
        {
            int i = 0, j = 0;
            Console.Write("Enter a numberof rows: ");
            int rows = int.Parse(Console.ReadLine());
            Console.Write("Enter a numberof columns: ");
            int cols = int.Parse(Console.ReadLine());
            Console.Write("Enter a numberof mines: ");
            int mines = int.Parse(Console.ReadLine());
            int[,] board = new int[rows, cols];

            Mine_generate(board, rows, cols, mines);

            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    if(board[i,j] == -1)
                    {
                        continue;
                    }
                    else
                    {
                        board[i, j] = Check(board, i, j, rows, cols);
                    }
                }
            }

            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    if(board[i,j] == -1)
                    {
                        Console.Write("[" + board[i, j] + "]");
                    }
                    else
                    {
                        Console.Write("[ " + board[i, j] + "]");
                    }

                }
                Console.Write("\n");

            }
        }
    }
}