import QtQuick 2.15
import QtPositioning 5.15
import QtLocation 5.15

Item {
    id: item
    ListModel {
        id: mymodel
    }
    Map {
        id: map
        anchors.fill: parent
        plugin: Plugin {
            name: "osm"
        }
        center: QtPositioning.coordinate(56.3287, 44.002)
        zoomLevel: 15
        activeMapType: supportedMapTypes[3]
        MapItemView {
            z: polygon.z + 1
            model: mymodel
            delegate: MapPolygon {
                opacity: 0.5
                border.width: 1
                color: 'green'
                transformOrigin: "Bottom"
                rotation: model.angle
                path: [{
                        "latitude": model.coords.latitude + 0.002,
                        "longitude": model.coords.longitude - 0.006
                    }, {
                        "latitude": model.coords.latitude,
                        "longitude": model.coords.longitude
                    }, {
                        "latitude": model.coords.latitude + 0.002,
                        "longitude": model.coords.longitude + 0.006
                    }]
            }
        }
        MapPolygon {
            id: polygon
            border.width: 0
            //rotation: 50
        }
    }
    function moveMarker(index, baseLat, baseLon) {
        var coord = QtPositioning.coordinate(baseLat, baseLon)
        mymodel.set(index, {
                        "coords": coord
                    })
        var path = polygon.path
        path[index] = coord
        polygon.path = path
        map.center = QtPositioning.coordinate(baseLat, baseLon)
    }
    function addMarker(baseLat, baseLon, angle) {
        var coord = QtPositioning.coordinate(baseLat, baseLon)
        mymodel.append({
                           "coords": coord,
                           "angle": angle
                       })
        polygon.addCoordinate(coord)
        map.center = QtPositioning.coordinate(baseLat, baseLon)
    }
    function delMarker(baseLat, baseLon) {
        mymodel.clear()
        var coord = QtPositioning.coordinate(baseLat, baseLon)
        polygon.removeCoordinate(coord)
    }

    function rotate(index, angle) {
        mymodel.set(index, {
                        "angle": angle
                    })
    }
}
