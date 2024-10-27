const EventEmitter = require('events')

const customEmitter = new EventEmitter()

//on method, takes in 2 argument, name of the event and callback function
customEmitter.on('node_tutorial', () => {
    console.log('Really trying to make a comprehensive tutorial here')
})

customEmitter.on('node_tutorial', (fruit) => {
    console.log(`Notice how it is the same event name but also parameter ${fruit}`)
})

//emit method, takes in 1 argument, the name of the event it is listening for
customEmitter.emit('node_tutorial', 'mango')