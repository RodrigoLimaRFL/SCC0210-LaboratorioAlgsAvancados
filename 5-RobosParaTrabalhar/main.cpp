/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; // numero de dias

    cin >> n;

    int m; // numero de tarefas

    cin >> m;

    vector<pair<int, int>> dateLimit(m); // {dataLimite, numeroTarefa}

    for(int i = 0; i < m; i++)
    {
        cin >> dateLimit[i].first;
        dateLimit[i].second = i;
    }

    sort(dateLimit.begin(), dateLimit.end());

    int numberRobots = 1; // numero de robos necessarios

    vector<pair<int, int>> dateAndRobot(m); // {data que tarefa foi feita, robo que fez a tarefa}[index da tarefa]

    bool notEnoughRobots = false;

    for(int i = 0; ; i++)
    {
        int tasksCompleted = numberRobots * i;

        if(tasksCompleted >= m) // completou tarefas
        {
            break;
        }

        if (i >= n) // chegou ao final sem terminar tarefas
        {
            //cout << "robos insuficientes, data limite, data: " << i+1 << " tarefas concluidas:" << tasksCompleted << endl;
            numberRobots++;
            i = -1;
            continue;
        }

        for(int j = tasksCompleted; j < tasksCompleted + numberRobots; j++)
        {
            if(j >= m) // terminou tarefas
            {
                break;
            }

            if(dateLimit[j].first <= i) // passou da data limite
            {
                //cout << "robos insuficientes, passou data limite, tarefa: " << dateLimit[j].second << " data limite: " << dateLimit[j].first << " data: " << i+1 << endl;
                notEnoughRobots = true;
                break;
            }

            int task = dateLimit[j].second;

            dateAndRobot[task].first = i + 1; // data = i + 1
            dateAndRobot[task].second = j - tasksCompleted + 1; // numero robo

            //cout << "tarefa: " << task << " data:" << dateAndRobot[task].first << " robo:" << dateAndRobot[task].second << endl;
        }

        if(notEnoughRobots)
        {
            numberRobots++;
            i = -1;
            notEnoughRobots = false;
        }
    }
    
    cout << numberRobots << endl;

    for(int i = 0; i < m; i++)
    {
        cout << dateAndRobot[i].first << " " << dateAndRobot[i].second << endl;
    }

    return 0;
}