import * as THREE from 'https://unpkg.com/three@0.126/build/three.module.js';

export function createGraffiti(position = { x: 0, y: -5, z: 50 }, textureURL = './Texturas/EASTER.png') {
    const textureLoader = new THREE.TextureLoader();
    const graffitiTexture = textureLoader.load(textureURL);
    const graffitiMaterial = new THREE.MeshPhongMaterial({ map: graffitiTexture });
    const graffitiGeometry = new THREE.BoxGeometry(60, 45, 0.1);
    const graffiti = new THREE.Mesh(graffitiGeometry, graffitiMaterial);
    graffiti.position.set(position.x, position.y, position.z);
    return graffiti;
}
