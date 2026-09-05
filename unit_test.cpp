////////////////////////////////////////////////////////
// ECE 3574 Exercise: CMake using Catch - starter code
//
#define CATCH_CONFIG_MAIN  // This line tells Catch to provide a main() function
                           // - do this in one cpp file only
#include "catch.hpp"       // This line provides access to all Catch macros
                           // - do not modify catch.hpp
#include "treap.h"
#include <cassert>    
#include <cstdlib>

TEST_CASE("treap unit test1", "[treap]") {

	struct TreapNode *root = NULL; 
	root = insert(root, 50);
	
	TreapNode *res = search(root, 50);
	REQUIRE(res->key == 50);

}

TEST_CASE("treap unit test2", "[treap]") {
	struct TreapNode* root = NULL;
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	REQUIRE(search(root, 20)->key == 20);
	REQUIRE(search(root, 100) == NULL);
}	

TEST_CASE("treap unit test3", "[treap]") {
	struct TreapNode* root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = deleteNode(root, 10);
	REQUIRE(root != NULL);
	REQUIRE(search(root, 10) == NULL);
	REQUIRE(search(root, 20)->key == 20);
}

TEST_CASE("treap unit test4", "[treap]") {
	struct TreapNode* root = NULL;
	root = insert(root, 15);
	root = insert(root, 25);
	root = deleteNode(root, 30);
	REQUIRE(root != NULL);
	REQUIRE(search(root, 15)->key == 15);
	REQUIRE(search(root, 25)->key == 25);
	root = deleteNode(root, 25);
	REQUIRE(search(root, 25) == NULL);
}

TEST_CASE("treap unit test5", "[treap]") {

	struct TreapNode* root = NULL;
	root = insert(root, 5);
	root = insert(root, 15);
	root = insert(root, 25);
	root = deleteNode(root, 15); // deleting node with two children
	REQUIRE(root != NULL);
	REQUIRE(search(root, 15) == NULL);
	REQUIRE(search(root, 5)->key == 5);
	REQUIRE(search(root, 25)->key == 25);

	root = deleteNode(root, 5); // deleting root node
	root = deleteNode(root, 25); // delete last node
	REQUIRE(root == NULL);
	REQUIRE(search(root, 5) == NULL);
	REQUIRE(search(root, 25) == NULL);
}

TEST_CASE("treap unit test6", "[treap]") {

	struct TreapNode* root = NULL;

	root = insert(root, 100);
	root = insert(root, 200);

	root = deleteNode(root, 9);
	REQUIRE(root != NULL);
	REQUIRE(search(root, 100)->key == 100);
	REQUIRE(search(root, 200)->key == 200);
	REQUIRE(search(root, 9) == NULL);
	REQUIRE(search(root, 100) != NULL);
	REQUIRE(search(root, 200) != NULL);
}