#include <CGAL/Epick_d.h>
#include <CGAL/point_generators_d.h>
#include <CGAL/Manhattan_distance_iso_box_point.h>
#include <CGAL/K_neighbor_search.h>
#include <CGAL/Search_traits_d.h>
#include "vectorizar.h"
#include <list>


typedef CGAL::Epick_d<CGAL::Dimension_tag<48*48> > Kernel;
typedef Kernel::Point_d Point_d;
typedef CGAL::Random_points_in_cube_d<Point_d> Random_points_iterator;
typedef Kernel::Iso_box_d Iso_box_d;
typedef Kernel TreeTraits;
typedef CGAL::Manhattan_distance_iso_box_point<TreeTraits> Distance;
typedef CGAL::K_neighbor_search<TreeTraits, Distance> Neighbor_search;
typedef Neighbor_search::Tree Tree;

vector<Point_d> tester () {
    ifstream infile("sample.txt");
    string path;
    vector<Point_d> myPoints;

    while(getline(infile, path)) {
        auto carac = Vectorizar(path);
        Point_d myPoint(carac.begin(), carac.end());
        myPoints.push_back(myPoint);       

    }
    return myPoints;
}



int  main() {
  const int N = 1000;
  const unsigned int K = 10;
  
  vector<Point_d> datos = tester();
  Tree tree;

  for(int i = 0; i < datos.size(); i++){
    tree.insert(datos[i]);
  }
  Point_d pp = datos[0];
  Point_d qq = datos[1];
  Iso_box_d query(pp, qq);
  Distance tr_dist;
  Neighbor_search N1(tree, query, 5, 10.0, false); // eps=10.0, nearest=false
  std::cout << "For query rectangle = [0.1, 0.2]^4 " << std::endl
            <<  "the " << K << " approximate furthest neighbors are: " << std::endl;
  for (Neighbor_search::iterator it = N1.begin();it != N1.end();it++) {
    std::cout << " Point " << it->first << " at distance  " << tr_dist.inverse_of_transformed_distance(it->second) << std::endl;
  }

  
  return 0;
}
