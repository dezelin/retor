
// Link to Boost
#define BOOST_TEST_DYN_LINK

// Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "libretor"

// VERY IMPORTANT - include this last
#include <boost/test/unit_test.hpp>

#include "retor.h"

// ------------- Tests Follow --------------

BOOST_AUTO_TEST_CASE(dummy_test)
{
    BOOST_CHECK(dummy == 0);
}
