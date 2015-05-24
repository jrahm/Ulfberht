#ifndef INCLUDE_ULFBERHT_COLLECTIONS_PATHTREE_
#define INCLUDE_ULFBERHT_COLLECTIONS_PATHTREE_

/*
 * Author: jrahm
 * created: 2015/05/24
 * PathTree.hpp: <description>
 */

#include <map>
#include <vector>
#include <string>

#include <cstdio>

namespace collections {

template <class ElemT, class PathElemT=std::string>
class PathTree {
public:
    PathTree(): has_element(false) {};
    const ElemT& getElement() const { return element; }
    ElemT& getElement() { return element; }

    void setElement(const ElemT& elem) { element = elem; has_element = true; } 

    bool HasElement()
        { return has_element; }

    PathTree* getSubTree(const PathElemT& pathelem) {
        typename std::map<PathElemT, PathTree*>::iterator itr;
        itr = m_children.find(pathelem);
        if(itr == m_children.end())
            return NULL;
        return itr->second;
    }

    const PathTree* getSubTree(const PathElemT& pathelem) const {
        return static_cast<const PathTree*>(
            static_cast<PathTree*>(this)->getSubTree(pathelem)
        );
    }

    PathTree* navigate(const std::vector<PathElemT>& vec) {
        return _navigate(vec, 0);
    }

    const PathTree* navigate(const std::vector<PathElemT>& vec) const {
        return static_cast<const PathTree*>(_navigate(vec, 0));
    }

    PathTree& get(const std::vector<PathElemT>& vec) {
        return _get(vec, 0);
    }

    template <class VisitorT>
    void walk( VisitorT& fn ) {
        std::vector<PathElemT> path;
        _walk(fn, path);
    }

private:

    template <class VisitorT>
    void _walk( VisitorT& fn, std::vector<PathElemT>& curpath ) {
        typename std::map<PathElemT,PathTree*>::iterator itr;

        if(has_element)
            fn(curpath, getElement());

        for(itr = m_children.begin(); itr != m_children.end(); ++ itr) {
            curpath.push_back(itr->first);
            itr->second->_walk(fn, curpath);
            curpath.pop_back();
        }
    }
    PathTree* _navigate(const std::vector<PathElemT>& vec, size_t i) {
        if(i == vec.size()) return this;
        PathTree* next = getSubTree(vec[i]);
        if(next) return next->_navigate(vec, i+1);
        return NULL;
    }

    PathTree& _get(const std::vector<PathElemT>& vec, size_t i) {
        if(i == vec.size()) return * this;

        PathTree* next = m_children[vec[i]];
        if(!next) {
            next = new PathTree();
            m_children[vec[i]] = next;
        }

        return next->_get(vec, i + 1);
    }

    std::map<PathElemT, PathTree*> m_children;
    ElemT element;
    bool has_element;
};

};

#endif /* INCLUDE_ULFBERHT_COLLECTIONS_PATHTREE_ */
