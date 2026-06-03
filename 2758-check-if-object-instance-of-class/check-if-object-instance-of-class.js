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
 let currentproto=Object.getPrototypeOf(Object(obj));
 while(currentproto!=null
 ){
    if(currentproto===classFunction.prototype){
        return true;
    }
    currentproto=Object.getPrototypeOf(currentproto);
 }
 return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */