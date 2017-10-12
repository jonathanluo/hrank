
/**
* Since we are exporting heap allocated values from dll:s on Windows,
* we need a mechanism to transfer this between different C runtime heaps.
*
* @author ch  2009.02.17
*/
#ifndef COH_EXAMPLES_POF_HPP
#define COH_EXAMPLES_POF_HPP

#if defined(_WINDOWS) || defined(WIN32)
#  pragma warning (disable : 4251)
#  pragma warning (disable : 4996)
#  ifdef _USRDLL
#     define COH_POF_EXPORT __declspec(dllexport)
#     define EXTERN_IMP
#  else
#     define COH_POF_EXPORT __declspec(dllimport)
#     define EXTERN_IMP extern
#  endif //_USRDLLS
#else
#  define COH_POF_EXPORT
#endif //_WINDOWS

/**
* Returns a hash code for a character array.
*
* @param psValue  the String to calculate the hash value for
*
* @return the hash code of the String
*/
COH_POF_EXPORT size_t hash(const char* psValue);

#endif //COH_EXAMPLES_POF_HPP
