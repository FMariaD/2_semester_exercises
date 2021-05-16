#include<vector>
#include<chrono>
#include<random>
#include<iostream>
#include<algorithm>
#include<cassert>
#include <fstream>

using namespace std;
using namespace std::chrono;

constexpr int max_value = 100000;

//символ "&" позволяет менять непосредственно ту переменную, которая передана в функцию
//как питоновский объект
//это замена указателя в современном c++
void bubble_sort(vector<int>& v) {
    int v_size = v.size();
    int tmp, i;
    while (v_size > 1) {
        for (i = 0; i < v_size - 1; i++) {
            if (v[i] > v[i+1])
            {
                tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
            }
        }
        v_size -= 1;
    }
}

void shaker_sort(vector<int>& v) {
    int v_end = v.size() - 1, v_start = 0;
    int tmp, i;
    while (v_end - v_start > 0) {
        for (i = v_start; i < v_end; i++) {
            if (v[i] > v[i+1])
            {
                tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
            }
        }
        v_end -= 1;
        for (i = v_end; i > v_start; i--) {
            if (v[i] < v[i-1])
            {
                tmp = v[i];
                v[i] = v[i-1];
                v[i-1] = tmp;
            }
        }
        v_start += 1;
    }
}

void insert_sort(vector<int>& v) {
    int tmp, i, j, k;
    for (i = 1; i < v.size(); i++)
    {
        k = i;
        for (j = i - 1; j >= 0; j--)
        {
            if (v[k] < v[j])
            {
                tmp = v[k];
                v[k] = v[j];
                v[j] = tmp;
                k = j;
            }
            else
            {
                break;
            }
        }
    }

}

void merge_vectors(vector<int>& v, int l, int m, int r) {
    if (r <= l) {return;}
    int i, j, k;
    int* tmp_v = new int[r - l + 1];
    for (i = l; i <= m; i++) {tmp_v[i-l] = v[i];}
    for (j = m+1; j <= r; j++) {tmp_v[j-l] = v[j];}
    i = 0;
    j = m+1 - l;
    for (k = l; k <= r; k++)
    {
        if ((i <= m - l)&&(j <= r - l))
        {
            v[k] = tmp_v[i] < tmp_v[j] ? tmp_v[i] : tmp_v[j];
            tmp_v[i] < tmp_v[j] ? i = i + 1 : j = j + 1;
        }
        else
        {
            if (j <= r - l)
            {
            v[k] = tmp_v[j];
            j++;
            }
            else if (i <= m - l)
            {
            v[k] = tmp_v[i];
            i++;
            }
        }
    }
    delete[]tmp_v;
}

void merge_sort(vector<int>& v, int l, int r) {
    if (r <= l) {return;}
    if (r - l == 1)
    {
        int tmp, i;
        if (v[r] > v[l])
        {
            tmp = v[r];
            v[r] = v[l];
            v[l] = tmp;
        }
        return;
    }
    int m = (r+l) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge_vectors(v, l, m, r);
}


void std_sort(vector<int>& v) {
    sort(v.begin(), v.end());
}

void stupid_sort(vector<int>& v) {
    int v_size = v.size();
    int tmp, i, s=1;
    while (s != 0) {
        for (i = 0; i < v_size - 1; i++) {
            if (v[i] > v[i+1])
            {
                tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
                break;
            }
            else if (i == v_size - 2)
            {
                s = 0;
            }
        }
    }
}

void Shell_sort(vector<int>& v)
{
    int d, v_size, tmp, i, j;
    v_size = v.size();
    d = v_size;

    while (d > 0)
    {
        for (i = 0; i < v_size - d; i++)
        {
            j = i;
            while ((j >= 0)&&(v[j] > v[j + d]))
            {
                tmp = v[j];
                v[j] = v[j + d];
                v[j + d] = tmp;
                j -= 1;
            }
        }
        d = d/2;
    }
}


vector<int> generate_random_vector(uint64_t n) {

    vector<int> ret(n);

    //это математически строгий и надежный способ генерировать случайные числа
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, max_value);

    for (int i = 0; i < n; ++i) {
        ret[i] = dist(gen);
    }

    return ret;
}


//это магическая строчка
//благодаря этому функция может принимать аргумент произвольного типа
//название для конкретно этого типа вы придумываете сами (я назвал его SortFunction)
template<typename SortFunction>
int benchmark(SortFunction f, uint64_t n) {

    auto v = generate_random_vector(n);
    auto start = steady_clock::now();
    //время засекается внутри этого блока
    f(v);
    auto finish = steady_clock::now();
    //for (int i = 0; i < v.size(); i++)
    //{
        //cout << v[i] << " ";
    //}
    //cout << endl;

    //это проверка на то, верно ли проведена сортировка
    //в случае ошибки программа падает с сообщением "assertion failed"

    assert(is_sorted(begin(v), end(v)));

    //возвращаем время работы в мс
    return duration_cast<milliseconds>(finish - start).count();
}

int main()
{
    int n, i, time, average_time;
    ofstream fout("std_sort.csv", ios_base::out);
    fout << "iteration,time\n";
    for (n = 1000; n < 1000000; n = n + 1000)
    {
        average_time = 0;
        // считаем 10 раз для одного значения n, чтобы усреднить по времени
        for (i = 0; i < 10; i++)
        {
            time = benchmark(std_sort, n);
            average_time += time;
        }
        average_time = average_time / 10;
        fout << n << ";" << average_time << "\n";
        cout << n << " " <<endl;
    }
    fout.close();
    return 0;
}
