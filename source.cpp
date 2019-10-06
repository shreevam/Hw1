#include <fstream>
#include <string.h>
#include <unistd.h>

using namespace std;

int main()
{
	ofstream outFS;
	outFS.open("test.txt");
	int pid;
	int id = 0;
	int fd[3][2];
	pipe(fd[0]);
	pipe(fd[1]);
	pipe(fd[2]);
	for (int x = 0; x < 3; x++)
	{
		pid = fork();
		id++;
		if (pid == 0)
			break;
	}
	if (pid > 0)
	{
		char input[1];
		close(fd[2][1]);
		read(fd[2][0], input, 1);
		if (input[0] == '1')
		{
			outFS << "Got true value" << endl;
		}
		else
		{
			outFS << "Got false value" << endl;
		}
	}
	else
	{
		if (id == 1)
		{
			close(fd[0][0]);
			write(fd[0][1], "1", 1);
			outFS << "ID 1 wrote" << endl;
			close(fd[0][1]);
			return 0;
		}
		else if (id == 2)
		{
			close(fd[1][0]);
			write(fd[1][1], "0", 1);
			outFS << "ID 2 wrote" << endl;
			close(fd[1][1]);
			return 0;
		}
		else if (id == 3)
		{
			char input[1];
			close(fd[0][1]);
			close(fd[1][1]);
			read(fd[0][0], input, 1);
			bool left = input[0] == '1';
			outFS << "Left input is " << left << endl;

			read(fd[1][0], input, 1);
			bool right = input[0] == '1';
			outFS << "Right input is " << right << endl;
			if (left || right)
			{
				write(fd[2][1], "1", 1);
			}
			else
			{
				write(fd[2][1], "0", 1);
			}
			close(fd[2][1]);
			return 0;
		}
	}
	return 0;
}
