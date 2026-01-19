#ifndef EDRA_DEF_HPP
#define EDRA_DEF_HPP

#define EDRA_DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name

EDRA_DECLARE_HANDLE(EdraHandle);
EDRA_DECLARE_HANDLE(EdraModule);

#endif // !EDRA_DEF_HPP
