#include <rw.h>
#include <skeleton.h>

#include <assert.h>
//#include "RawMesh.h"
#include "GtMath.h"
#include "B4ConvexHull.h"
//#include "B3VehiclePhysics.h"
//#include "B3StreamedTrack.h"
//#include "GtIntersection.h"
#include "PhysicsTestApp.h"

extern struct SceneGlobals {
	rw::World* world;
	rw::Camera* camera;
} Scene;

B4ConvexHull myHull;
rw::Clump* vehicleObject;
rw::Clump* trackObject;

//B3VehiclePhysics vehiclePhysics;

rw::V3d vehicleVelocity = { 0.0f, 0.0f, 0.0f };

//rw::Clump* CreateClumpFromMeshData2(const RawMesh& meshData)
//{
//	// Create a new clump.
//	rw::Clump* clump = rw::Clump::create();
//	if (!clump)
//		return nullptr;
//
//	// Create a root frame and assign it to the clump.
//	rw::Frame* rootFrame = rw::Frame::create();
//	if (!rootFrame)
//	{
//		clump->destroy();
//		return nullptr;
//	}
//	clump->setFrame(rootFrame);
//
//	// Determine the number of vertices and triangles.
//	int numVertices = static_cast<int>(meshData.vertices.size());
//	int numTriangles = static_cast<int>(meshData.triangles.size());
//
//	// Create geometry.
//	// Using flag 0 here (i.e. not NATIVE, no PRELIT, etc.)
//	rw::Geometry* geometry = rw::Geometry::create(numVertices, numTriangles,
//		rw::Geometry::TRISTRIP
//		| rw::Geometry::TEXTURED
//		| rw::Geometry::PRELIT
//		| rw::Geometry::NORMALS
//		| rw::Geometry::MODULATE
//	);
//	if (!geometry)
//	{
//		rootFrame->destroy();
//		clump->destroy();
//		return nullptr;
//	}
//
//	// The Geometry::create call automatically sets up one morph target.
//	// Fill the vertex positions in the primary morph target.
//	rw::MorphTarget& mt = geometry->morphTargets[0];
//	for (int i = 0; i < numVertices; i++)
//	{
//		mt.vertices[i].x = static_cast<float>(meshData.vertices[i].x);
//		mt.vertices[i].y = static_cast<float>(meshData.vertices[i].y);
//		mt.vertices[i].z = static_cast<float>(meshData.vertices[i].z);
//	}
//
//
//	// Create a default material and add it to the geometry's material list.
//	geometry->matList.init();
//	rw::Material* material = rw::Material::create();
//	material->color = { 255, 255, 255, 255 };
//	material->surfaceProps = { 1.0, 0.0, 0.0 };
//
//	rw::Image::setSearchPath("");
//	rw::Texture* tex = rw::Texture::read("whiteash", nil);
//	material->setTexture(tex);
//
//	rw::int32 matIndex = geometry->matList.appendMaterial(material);
//	material->destroy();
//
//	// Set a default texture coordinate.
//	//rw::TexCoords uv = { 0.0f, 0.0f };
//	*geometry->texCoords = new rw::TexCoords[8];
//
//	for (int i = 0; i < 8; i++)
//	{
//		geometry->texCoords[i] = new rw::TexCoords;
//	}
//
//	*geometry->texCoords[0] = { 0.0f, 0.0f };
//	*geometry->texCoords[1] = { 0.0f, 1.0f };
//	*geometry->texCoords[2] = { 1.0f, 0.0f };
//	*geometry->texCoords[3] = { 1.0f, 1.0f };
//	*geometry->texCoords[4] = { -1.0f, 0.0f };
//	*geometry->texCoords[5] = { 0.0f, -1.0f };
//	*geometry->texCoords[6] = { -1.0f, -1.0f };
//	*geometry->texCoords[7] = { 0.0f, 0.0f };
//
//	// Fill the triangle data from the mesh.
//	for (int i = 0; i < numTriangles; i++)
//	{
//		geometry->triangles[i].v[0] = meshData.triangles[i].v1;
//		geometry->triangles[i].v[1] = meshData.triangles[i].v2;
//		geometry->triangles[i].v[2] = meshData.triangles[i].v3;
//		geometry->triangles[i].matId = matIndex;
//	}
//
//	// Calculate the geometry’s bounding sphere.
//	geometry->calculateBoundingSphere();
//
//	// Create an atomic, assign the geometry and set its frame.
//	rw::Atomic* atomic = rw::Atomic::create();
//	geometry->buildMeshes();
//	atomic->setGeometry(geometry, 0);
//	atomic->setFrame(rootFrame);
//
//	// Add the atomic to the clump.
//	clump->addAtomic(atomic);
//
//	// Release our local reference to geometry.
//	geometry->destroy();
//
//	return clump;
//}

namespace PhysicsTestApp
{

	void Init()
	{
		// 1. Create an instance of CB3StreamedTrack.
	// Its constructor will call InitializeHardcodedKDTFromPlane to set up
	// g_HardcodedTrackCollision with a plane at Y=0.
		//B3StreamedTrack myTrack;

		//// 2. Define a sphere for intersection testing.
		//GtMath::GtSphere testSphere;

		//// Test case 1: Sphere intersecting the Y=0 plane
		//testSphere.center = { 10.0f, 0.5f, 10.0f }; // Slightly above the plane
		//testSphere.radius = 1.0f;                      // Radius large enough to intersect

		//printf("\nTesting sphere 1 (expected to intersect Y=0 plane):\n");
		//printf("Sphere center: (%.1f, %.1f, %.1f), radius: %.1f\n",
		//	testSphere.center.x, testSphere.center.y, testSphere.center.z, testSphere.radius);

		//UserCollisionData collisionData1 = { 0 };
		//bool searchCompleted1 = myTrack.IntersectSphereWithUnit(
		//	0, // unitIndex is ignored in the hardcoded version
		//	testSphere,
		//	MySphereCollisionCallback,
		//	&collisionData1
		//);

		//if (searchCompleted1) {
		//	printf("Sphere 1 intersection search completed.\n");
		//}
		//else {
		//	printf("Sphere 1 intersection search was stopped by callback.\n");
		//}
		//printf("Sphere 1 Total hits: %d\n", collisionData1.hitCount);
		//if (collisionData1.hitCount > 0) {
		//	printf("Sphere 1: Intersection detected with the plane.\n");
		//}
		//else {
		//	printf("Sphere 1: No intersection detected.\n");
		//}

		//printf("-------------------------------------------\n");

		//// Test case 2: Sphere NOT intersecting the Y=0 plane
		//testSphere.center = { 20.0f, 5.0f, 20.0f }; // Far above the plane
		//testSphere.radius = 1.0f;

		//printf("\nTesting sphere 2 (expected NOT to intersect Y=0 plane):\n");
		//printf("Sphere center: (%.1f, %.1f, %.1f), radius: %.1f\n",
		//	testSphere.center.x, testSphere.center.y, testSphere.center.z, testSphere.radius);

		//UserCollisionData collisionData2 = { 0 };
		//bool searchCompleted2 = myTrack.IntersectSphereWithUnit(
		//	0, // unitIndex ignored
		//	testSphere,
		//	MySphereCollisionCallback,
		//	&collisionData2
		//);

		//if (searchCompleted2) {
		//	printf("Sphere 2 intersection search completed.\n");
		//}
		//else {
		//	printf("Sphere 2 intersection search was stopped by callback.\n");
		//}
		//printf("Sphere 2 Total hits: %d\n", collisionData2.hitCount);
		//if (collisionData2.hitCount > 0) {
		//	printf("Sphere 2: Intersection detected (UNEXPECTED for this test case if plane is Y=0 and sphere is far above).\n");
		//}
		//else {
		//	printf("Sphere 2: No intersection detected (as expected).\n");
		//}

		//printf("-------------------------------------------\n");

		//// Test case 3: Sphere fully below the Y=0 plane but still intersecting
		//testSphere.center = { 30.0f, -0.5f, 30.0f };
		//testSphere.radius = 1.0f;

		//printf("\nTesting sphere 3 (expected to intersect Y=0 plane from below):\n");
		//printf("Sphere center: (%.1f, %.1f, %.1f), radius: %.1f\n",
		//	testSphere.center.x, testSphere.center.y, testSphere.center.z, testSphere.radius);

		//UserCollisionData collisionData3 = { 0 };
		//bool searchCompleted3 = myTrack.IntersectSphereWithUnit(
		//	0, // unitIndex ignored
		//	testSphere,
		//	MySphereCollisionCallback,
		//	&collisionData3
		//);
		//if (searchCompleted3) {
		//	printf("Sphere 3 intersection search completed.\n");
		//}
		//else {
		//	printf("Sphere 3 intersection search was stopped by callback.\n");
		//}
		//printf("Sphere 3 Total hits: %d\n", collisionData3.hitCount);
		//if (collisionData3.hitCount > 0) {
		//	printf("Sphere 3: Intersection detected with the plane.\n");
		//}
		//else {
		//	printf("Sphere 3: No intersection detected.\n");
		//}


		//vehiclePhysics = B3VehiclePhysics();
		//vehiclePhysics.Construct();



		//// Max possible values (adjust as needed based on game data)
		//const int MAX_HULL_VERTICES = 32; // Example
		//const int MAX_HULL_FACES = 60;    // Example (Box: 12, Cone: 6)
		//const int MAX_HULL_PLANES = 60;   // Same as faces
		//const int MAX_HULL_EDGES = 90;    // Example (Box: 18 from decompiled, or 12 unique)

		//myHull.m_pVertices = new GtMath::GtV3d[MAX_HULL_VERTICES];
		//myHull.m_pFaces = new B3Face[MAX_HULL_FACES];
		//myHull.m_pPlanes = new GtMath::GtPlane[MAX_HULL_PLANES];
		//myHull.m_pEdges = new B3Edge[MAX_HULL_EDGES];
		//// For DeformHullVerts, also m_pDeformVerts
		//// myHull.m_pDeformVerts = new CB3DeformVert[MAX_HULL_VERTICES];


		//GtMath::GtV3d minB = { -1, -1, -1 };
		//GtMath::GtV3d maxB = { 1, 1, 1 };
		//myHull.MakeBoxFromBoundingBox(minB, maxB);
		//// ... or myHull.MakeConeFromBoundingBox(minB, maxB); etc.
		//// Then myHull.ScaleAndFillInHullDetails(minB, maxB) for cone/boat.

		//// Don't forget to delete[] the allocated memory in a destructor or when done.


		//// Create a box mesh
		//RawMesh boxMesh;
		//boxMesh.vertices = {
		//	{ -1.0f, -1.0f, -1.0f },
		//	{  1.0f, -1.0f, -1.0f },
		//	{  1.0f,  1.0f, -1.0f },
		//	{ -1.0f,  1.0f, -1.0f },
		//	{ -1.0f, -1.0f,  1.0f },
		//	{  1.0f, -1.0f,  1.0f },
		//	{  1.0f,  1.0f,  1.0f },
		//	{ -1.0f,  1.0f,  1.0f }
		//};
		//boxMesh.triangles = {
		//	{ 0, 1, 2 }, { 0, 2, 3 },
		//	{ 4, 5, 6 }, { 4, 6, 7 },
		//	{ 0, 1, 5 }, { 0, 5, 4 },
		//	{ 2, 3, 7 }, { 2, 7, 6 },
		//	{ 0, 3, 7 }, { 0, 7, 4 },
		//	{ 1, 2, 6 }, { 1, 6, 5 }
		//};

		//vehicleObject = CreateClumpFromMeshData2(boxMesh);
		//Scene.world->addClump(vehicleObject);


		//// Create a large floor mesh
		//RawMesh floorMesh;
		//floorMesh.vertices = {
		//	{ -10.0f, 0.0f, -10.0f },
		//	{  10.0f, 0.0f, -10.0f },
		//	{  10.0f, 0.0f,  10.0f },
		//	{ -10.0f, 0.0f,  10.0f }
		//};
		//floorMesh.triangles = {
		//	{ 0, 1, 2 }, { 0, 2, 3 }
		//};

		/*trackObject = CreateClumpFromMeshData2(floorMesh);
		Scene.world->addClump(trackObject);*/



		// Set an initial position for the camera
		rw::Frame* cameraFrame = Scene.camera->getFrame();
		if (cameraFrame) { // Camera should have a frame by default
			rw::V3d cameraPos = { 0.0f, 2.0f, -8.0f }; // Position camera slightly up and back
			cameraFrame->translate(&cameraPos, rw::COMBINEREPLACE);
		}

	}

	void UpdateVehicle(float deltaTime)
	{
		// Update vehicle position based on velocity
		rw::Frame* clumpFrame = vehicleObject->getFrame();
		rw::Matrix transform = *clumpFrame->getLTM();
		rw::V3d translation;

		translation.x = vehicleVelocity.x * deltaTime;
		translation.y = vehicleVelocity.y * deltaTime;
		translation.z = vehicleVelocity.z * deltaTime;
		clumpFrame->translate(&translation, rw::COMBINEPRECONCAT);
	}

	void UpdateCamera(float deltaTime)
	{
		rw::Frame* cameraFrame = Scene.camera->getFrame();
		rw::Frame* clumpFrame = vehicleObject->getFrame();

		// Get the world position of the clump's center (its frame's position)
		rw::V3d targetPosition = clumpFrame->getLTM()->pos;
		rw::V3d cameraPosition = cameraFrame->getLTM()->pos;
		targetPosition = rw::sub(targetPosition, cameraPosition);

		// Define the 'up' vector for the camera (typically positive Y)
		rw::V3d upVector = { 0.0f, 1.0f, 0.0f };

		// Make the camera frame look at the target position
		cameraFrame->matrix.lookAt(targetPosition, upVector);
		cameraFrame->updateObjects(); // Important: Update matrices after transformation
	}

	void Update(float deltaTime)
	{

		UpdateVehicle(deltaTime);
		UpdateCamera(deltaTime);


		rw::SetRenderState(rw::ZTESTENABLE, 1);
		rw::SetRenderState(rw::ZWRITEENABLE, 1);
		rw::SetRenderState(rw::SRCBLEND, rw::BLENDONE);
		rw::SetRenderState(rw::DESTBLEND, rw::BLENDZERO);
		rw::SetRenderState(rw::TEXTUREFILTER, rw::Texture::FilterMode::LINEAR);
		rw::SetRenderState(rw::CULLMODE, rw::CULLNONE);

		static ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.15f, 1.00f); // Darker background
		rw::RGBA clearcol = rw::makeRGBA(clear_color.x * 255, clear_color.y * 255, clear_color.z * 255, clear_color.w * 255);

		Scene.camera->clear(&clearcol, rw::Camera::CLEARIMAGE | rw::Camera::CLEARZ);
		Scene.camera->beginUpdate();

		Scene.world->render();



		rw::Matrix* transform = rw::Matrix::create();
		//myHull.DebugRenderPlanes(*transform, myHull.m_pPlanes, myHull.m_pVertices, false);


		ImGui_ImplRW_NewFrame(deltaTime);

		ImGuiIO& io = ImGui::GetIO();
		ImVec2 window_pos = ImVec2(0, 0);
		ImVec2 window_pos_pivot = ImVec2(0, 0);
		ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
		ImGui::SetNextWindowBgAlpha(0.85f); // Slightly transparent background

		ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoResize |
			ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_AlwaysAutoResize |
			ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoFocusOnAppearing | // Don't steal focus initially
			ImGuiWindowFlags_NoNav;               // We handle nav manually

		if (ImGui::Begin("Debug", 0, window_flags)) {
			ImGui::Text("Delta Time: %.3f", deltaTime);
			ImGui::Text("Vehicle Position: (%.2f, %.2f, %.2f)", vehicleObject->getFrame()->getLTM()->pos.x, vehicleObject->getFrame()->getLTM()->pos.y, vehicleObject->getFrame()->getLTM()->pos.z);
			ImGui::Text("Vehicle Velocity: (%.2f, %.2f, %.2f)", vehicleVelocity.x, vehicleVelocity.y, vehicleVelocity.z);
		}
		ImGui::End();

		ImGui::EndFrame();
		ImGui::Render();

		ImGui_ImplRW_RenderDrawLists(ImGui::GetDrawData());

		Scene.camera->endUpdate();
		Scene.camera->showRaster(0);
	}

	void KeyDown(int key)
	{
		// Handle key presses to control vehicle movement
		switch (key) {
		case sk::KEY_UP: // Move forward
			vehicleVelocity.z = 1.0f;
			break;
		case sk::KEY_DOWN: // Move backward
			vehicleVelocity.z = -1.0f;
			break;
		case sk::KEY_LEFT: // Turn left
			vehicleVelocity.x = -1.0f;
			break;
		case sk::KEY_RIGHT: // Turn right
			vehicleVelocity.x = 1.0f;
			break;
		}

	}

	void KeyUp(int key)
	{
		// Handle key releases to stop vehicle movement
		switch (key) {
		case sk::KEY_UP: // Stop moving forward
			vehicleVelocity.z = 0.0f;
			break;
		case sk::KEY_DOWN: // Stop moving backward
			vehicleVelocity.z = 0.0f;
			break;
		case sk::KEY_LEFT: // Stop turning left
			vehicleVelocity.x = 0.0f;
			break;
		case sk::KEY_RIGHT: // Stop turning right
			vehicleVelocity.x = 0.0f;
			break;
		}

	}

	sk::EventStatus
		AppEventHandler(sk::Event e, void* param)
	{
		using namespace sk;
		Rect* r;
		MouseState* ms;

		ImGuiEventHandler(e, param);
		ImGuiIO& io = ImGui::GetIO();

		switch (e) {
		case INITIALIZE:
			Init();
			return EVENTPROCESSED;
		case KEYDOWN:
			KeyDown(*(int*)param);
			return EVENTPROCESSED;
		case KEYUP:
			KeyUp(*(int*)param);
			return EVENTPROCESSED;
		case IDLE:
			Update(*(float*)param);
			return EVENTPROCESSED;
		}
		return sk::EVENTNOTPROCESSED;
	}

}