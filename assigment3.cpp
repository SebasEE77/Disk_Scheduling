#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <sstream>

using namespace std;

// Se asume que el escaneo siempre comienza desde arriba
tuple<int, vector<int>> scan(int ini, vector<int> requests, int lim) {
    sort(requests.begin(), requests.end());

    vector<int> under = {0}; // se agrega el límite inferior de las pistas
    vector<int> over;
    int i = 0;
    while (i < requests.size() && requests[i] < ini) {
        under.push_back(requests[i]);
        i++;
    }
    reverse(under.begin(), under.end());
    over = vector<int>(requests.begin() + i, requests.end());
    
    over.push_back(lim);    // se agrega el límite superior de las pistas
    vector<int> path(over.begin(), over.end());
    path.insert(path.end(), under.begin(), under.end());
    
    int dist = 0;
    int curr = ini;
    for (int r : path) {
        dist += abs(r - curr);
        curr = r;
    }
    
    return make_tuple(dist, path);
}

tuple<int, vector<int>> cscan(int ini, vector<int> requests, int lim) {
    sort(requests.begin(), requests.end());

    vector<int> under = {0}; vector<int> over;
    int i = 0;
    while (i < requests.size() && requests[i] < ini) {
        under.push_back(requests[i]);
        i++;
    }
    over = vector<int>(requests.begin() + i, requests.end());
    over.push_back(lim);
    vector<int> path(over.begin(), over.end());
    path.insert(path.end(), under.begin(), under.end());
    
    int dist = 0;
    int curr = ini;
    for (int r : path) {
        dist += abs(r - curr);
        curr = r;
    }
    return make_tuple(dist,path);
}

int main() {
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        string alg;
        int cantRequests, pistas, t;
        ss >> alg >> cantRequests >> pistas >> t;

        vector<int> requests(cantRequests);
        for (int i = 0; i < cantRequests; i++) {
            getline(cin, line);
            stringstream iss(line);
            iss >> requests[i];
        }

        tuple<int, vector<int>> result;
        if (alg == "SCAN") {
            result = scan(requests[0], requests, pistas);
        } else {
            result = cscan(requests[0], requests, pistas);
        }

        cout << "Para las solicitudes ";
        for (int r : requests) {
            cout << r << " ";
        }
        cout << endl;

        cout << "El recorrido " << alg << " es" << endl;
        for (int i = 0; i < get<1>(result).size(); i++) {
            cout << get<1>(result)[i];
            if (i < get<1>(result).size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;

        cout << "Con distancia total de " << get<0>(result) << endl;
        cout << "En un tiempo de " << get<0>(result)*t << " ms" << endl;
    }

    return 0;
}