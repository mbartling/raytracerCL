
#include "gtest/gtest.h"
#include "photon.h"
#include "spatialHash.h"
#include "vec.h"

SpatialHash mSpatialHash;

TEST(CheckAccess, WriteAndRead){
	photon p = photon();
	Vec3d  q = Vec3d(1.0, 1.0, 1.0);

	mSpatialHash[q] = p;
	EXPECT_EQ(true, mSpatialHash[q].flux == p.flux);
}

TEST(CheckAccess, Update){
	photon p = photon();
	p.flux = Vec3d(100.0, 100.0, 100.0);
	Vec3d q = Vec3d(10.0, 10.0, 10.0);

	mSpatialHash[q] = p;
	mSpatialHash[q] += p;

	EXPECT_GT(mSpatialHash[q].flux[0], p.flux[0]);

}

TEST(CheckMembers, NoCount){
	photon p = photon();
	Vec3d q = Vec3d(100.0, 100.0, 100.0);

	EXPECT_EQ(0, mSpatialHash.count(q));	
}

TEST(CheckMembers, ACount){
	photon p = photon();
	Vec3d q = Vec3d(1000.0, 1000.0, 1000.0);

	mSpatialHash[q] = p;
	EXPECT_EQ(true, mSpatialHash.count(q) != 0);	
}

TEST(CheckMembers, Size ){
	SpatialHash mSpatialHash1;
	photon p = photon();
	p.flux = Vec3d(100.0, 100.0, 100.0);
	Vec3d q1 = Vec3d(10.0, 10.0, 10.0);
	Vec3d q2 = Vec3d(100.0, 100.0, 100.0);


	mSpatialHash1[q1] = p;
	mSpatialHash1[q2] = p;
	EXPECT_EQ(mSpatialHash1.size(), 2);
}