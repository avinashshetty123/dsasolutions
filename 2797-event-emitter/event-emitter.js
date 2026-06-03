class EventEmitter {
    constructor(){
        this.event=new Map();
    }
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if(!this.event.has(eventName)){
            this.event.set(eventName,[]);
        }
        const listeners=this.event.get(eventName);
        listeners.push(callback);
        
        return {
            unsubscribe: () => {
                const index=listeners.indexOf(callback);
                if(index!==-1){
                    listeners.splice(index,1);
                }
                return undefined;
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        if(!this.event.has(eventName)){
            return [];
        }
        const listeners=this.event.get(eventName);
        const result=[];
        for(const call of listeners){
            result.push(call(...args));

        }
        return result;
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */