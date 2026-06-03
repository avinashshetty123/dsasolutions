/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
 if(typeof classFunction!=='function'||classFunction===null||classFunction===undefined){
    return false;
 }
 if(obj===null||obj===undefined){
    return false;
 }
 return Object(obj) instanceof classFunction;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */