import * as THREE from 'https://unpkg.com/three@0.126/build/three.module.js';

export function createTV(position = { x: 0, y: -10, z: 50 }, textureURL = './Skybox/tv.jpg') {
    const textureLoader = new THREE.TextureLoader();
    const tvTexture = textureLoader.load(textureURL);
    const tvMaterial = new THREE.MeshPhongMaterial({ map: tvTexture });
    const tvGeometry = new THREE.BoxGeometry(20, 15, 1);
    const tv = new THREE.Mesh(tvGeometry, tvMaterial);
    tv.position.set(position.x, position.y, position.z);
    return tv;
}
