#ifndef ___SPATIALHASH_H__
#define ___SPATIALHASH_H__

#include <tuple>
#include <unordered_map>
#include "photon.h"
#include "../vecmath/vec.h"
// #include <functional>
#include <boost/functional/hash.hpp>
//Will have to do this since the map takes a type not an object
const double r = 1.0; // 

template <typename T>
class mHash{
  // const double radius = 0.001;
  // const double radius = 0.0025;
  const double radius = 0.001;

  public:
    // mHash(): radius(r){}

    // Update this part to support whatever type we use for Point
    std::tuple<int, int, int> operator() ( T p ){
      return std::make_tuple( int(p.x()/radius), int(p.y()/radius), int(p.z()/radius));
    }

};

template <typename myhashT> 
class myMap{
  std::unordered_map<std::tuple<int, int, int>, photon, boost::hash<std::tuple<int, int, int>>> _map;
  myhashT _hash;
  public:

    photon operator[] (const Vec3d& point) const{
      // if (_map.count(point))
        return _map[_hash(point)];
      // else return photon();
    }
    photon& operator[] (const Vec3d& point){
      return _map[_hash(point)];
    }
    int count(const Vec3d& point ){return _map.count(_hash(point));}
    int size( void ){return _map.size();}

};

const int p1 = 73856093;
const int p2 = 19349663;
const int p3 = 83492791;
const int defaultSize = 10000000;
class mySpatialMap{
    //std::vector< std::vector< std::vector<photon> > > _map;
    std::vector< photon > _map;
    std::vector< int > _counts;
    int _count;
    int N; //size of the hash
    const double radius = 0.001;
    
    int hash(Vec3d p) const {
        int i = ( (uint(p.x()/radius) * p1) ^ (uint(p.y()/radius) * p2) ^ (uint(p.z()/radius) * p3)) % N;
        return i;
    }
    public:
    
    mySpatialMap(): N(defaultSize), _map(defaultSize), _counts(defaultSize) {
        photon p;
        for(int i = 0; i < _counts.size(); i++){
            _map[i] = p;
            _counts[i] = 0;
        }
    } 

    photon operator[] (const Vec3d& point) const {
        return _map[hash(point)];
    }
    photon& operator[] (const Vec3d& point) {
        _counts[hash(point)] += 1;
        _count += 1;
        return _map[hash(point)];
    }
    int count(const Vec3d& point) { return _counts[hash(point)]; }
    int size( void ) const { return _count; }
};
// spatialHash = unordered_map<Point, Photon, mHash>(); //Create the Spatial Hash
// using SpatialHash = std::unordered_map<Vec3d, photon, std::hash<mHash<Vec3d>>>;
using SpatialHash = myMap<mHash<Vec3d>>;
// using SpatialHash = mySpatialMap;

#endif /*___SPATIALHASH_H__*/
