A header that has a using directive or declaration at its top-level scope injects names into
every file that includes the header. Ordinarily, headers should define only the names that are part
of its interface, not names used in its own implementation. As a result, header files should not contain 
using directives or using declarations except inside functions or namespaces.
