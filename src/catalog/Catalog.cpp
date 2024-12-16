//
// Created by mohamed on 01/08/23.
//

#include <catalog/Catalog.h>

namespace catalog {
    Catalog* Catalog::instance = nullptr;
    Catalog::Catalog(BufferpoolManager* bpm):bpm(bpm){
    }
    Catalog* Catalog::getCatalog(BufferpoolManager* bpm){
        if(instance!=nullptr) return instance;
//        Page* catalogPage = bpm->fetchPage(CATALOG_PAGE_ID);
//        instance = new Catalog(bpm);
//        CatalogMapper::map(catalogPage,instance);
        return instance;
    }
} // catalog