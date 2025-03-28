
#include <bits/stdc++.h>

using namespace std;

int main() {
  int cd_capacidad, num_canciones;
  cin >> cd_capacidad >> num_canciones;

  vector<int> longitudes_canciones(num_canciones);
  for (int i = 0; i < num_canciones; i++) {
    cin >> longitudes_canciones[i];
  }

  sort(longitudes_canciones.rbegin(), longitudes_canciones.rend());

  int tiempo_cd1 = 0, tiempo_cd2 = 0;
  int espacio_libre_cd1 = cd_capacidad, espacio_libre_cd2 = cd_capacidad;

  for (int i = 0; i < num_canciones; i++) {

    if (tiempo_cd1 <= tiempo_cd2) {

      if (espacio_libre_cd1 >= longitudes_canciones[i]) {
        tiempo_cd1 += longitudes_canciones[i];
        espacio_libre_cd1 -= longitudes_canciones[i];
      } else {

        if (espacio_libre_cd2 >= longitudes_canciones[i]) {
          tiempo_cd2 += longitudes_canciones[i];
          espacio_libre_cd2 -= longitudes_canciones[i];
        }
      }
    } else {

      if (espacio_libre_cd2 >= longitudes_canciones[i]) {
        tiempo_cd2 += longitudes_canciones[i];
        espacio_libre_cd2 -= longitudes_canciones[i];
      } else {

        if (espacio_libre_cd1 >= longitudes_canciones[i]) {
          tiempo_cd1 += longitudes_canciones[i];
          espacio_libre_cd1 -= longitudes_canciones[i];
        }
      }
    }
  }



  cout << max(tiempo_cd1, tiempo_cd2) << " "<< min(tiempo_cd1, tiempo_cd2) << endl;;


  return 0;
}
