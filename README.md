# nomnoms

This repository has been stood up for a question on Stack Overflow to clarify a minimal but complete example of the "proper" way to setup a "modern" cmake project with components. The required usage (for a downstream library) should be nothing more than

  find_package(noms REQUIRED COMPONENTS fruit veg)

  /#..

  target_link_libraries(${project} PUBLIC noms::fruit noms::veg)

## structure

The repository contains two free-standing projects:

* The noms library
* The munch application which depends on noms and exists outside of the noms build tree

## non-goals

This is explicitly about demonstrating the setup required to use COMPONENTS in cmake, both in the upstream library and the consumer of that library. Anything else is out of scope.
