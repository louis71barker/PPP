#include <stdio.h>
#include <stdlib.h>


/*struct score{
    char*.Name;
    float.Score;
    char*.MainTask;
} Student1, Student2, Student3;
*/

typedef struct {
    char* name;
    float ScoreMaintask;
    float ScoreStretch1;
    float ScoreStretch2;
    float ScoreStructure;
    float ScoreFunction;
    float ScoreDocument;
    float ScoreTotal;

} Studentinfo;


void calTotalScore(Studentinfo *_data, int _numStudents)
{
    int i;

    for(i=0; i< _numStudents; ++i)
    {
        _data[i].ScoreTotal = _data[i].ScoreDocument + _data[i].ScoreFunction + _data[i].ScoreMaintask + _data[i].ScoreStretch1 + _data[i].ScoreStretch2 + _data[i].ScoreStructure;
    }
}

void calAverageScore(Studentinfo *_data, int _numStudents)
{
    int i, AverageScore;
    int ScoreSum = 0.0;

    for(i=0; i<_numStudents; i++)
    {
        ScoreSum += _data[i].ScoreTotal;
    }
    AverageScore = ScoreSum / _numStudents;
    printf("The Average Score is %f \n", AverageScore);
}

void SortTotalScore(Studentinfo *_data, int _numStudents)
{
    int i,j,k;

    for(i=0; i<_numStudents; i++)
    {
        for(j=i+1;j<_numStudents;j++)
        {
            if(_data[i].ScoreTotal>_data[j].ScoreTotal)
            {
                SwapRecord(_data);
            }
        }
    }
/*    printf("Final Scores are: ");
    for(i=0; i<)
*/
}

void SwapRecord(Studentinfo *_data, int _i, int _j)
{


    Studentinfo tmp;

    tmp = _data[_i];
    _data[_i] = _data[_j];
    _data[_j] = tmp;


    /*k=_numStudents[i];
    _numStudents[i] = _numStudents[j];
    _numStudents[j] = k;*/
}

void PrintFinalRecord(Studentinfo *_data, int _numStudents)
{
    int i;

    printf("The final Record for the students are:  \n");
    printf("name\tMain Task\tStretch 1\tStretch 2\tStructure\tFunction\tDocument\Total");
    for(i=0; i<_numStudents; i++)
    {
        printf("%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", _data[i].name, _data[i].ScoreTotal = _data[i].ScoreDocument + _data[i].ScoreFunction + _data[i].ScoreMaintask + _data[i].ScoreStretch1 + _data[i].ScoreStretch2 + _data[i].ScoreStructure);
    }
}

/*
 *int
 *
 *
*/

int main()
{
    Studentinfo data[]={
        {"Louis", 30, 10, 14, 7, 7, 9, 0},
        {"Teemu", 26, 9, 12, 8, 4, 7, 0},
        {"James", 24, 8, 13, 5, 5, 6, 0},
        {"Phil", 26, 13, 10, 6, 7, 9, 0},
        {"Matt", 22, 16, 12, 5, 7, 6, 0}
    };

    int _numStudents = sizeof (data)/sizeof(Studentinfo);

    calTotalScore(data,_numStudents);


    calAverageScore(data, _numStudents);


    SortTotalScore(data, _numStudents);


    PrintFinalRecord(data, _numStudents);
}
